package tools;

import java.sql.Connection;
import java.util.List;

import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import tools.db.DB;
import tools.db.DBConn;
import tools.to.ColumnItem;
import tools.to.DatabaseItem;
import tools.to.TableItem;

public class SqlTools {
	
	
	
	static UpdateResult updateDesc(DatabaseItem db, String ip, String user, String pwd) {
		String dbName = db.getName();
		List<TableItem> tables = db.getTables();
		System.out.println(tables.size());
		
		System.out.println("==== update database: " + dbName);
		int tableCount = 0;
		int columnCount = 0;
		
		Connection c = DBConn.getConn(ip, dbName, user, pwd);
		DB session = DB.open(c, dbName);
		
		for(TableItem tbl : tables) {
			String tableName = tbl.getName();
			if(!session.hasTable(tableName)) {
				System.out.println("table is not exists:" + tableName);
				continue;
			}
			
			tableCount++;
			
			for(ColumnItem col: tbl.getColumns()) {
				String colName = col.getColumn();
				if(!session.hasColumn(tableName, colName)) {
					System.out.println("column is not exists:" + colName + ", in table :" + tableName);
					continue;
				}
				
				String desc = col.getDesc();
				session.addDesc(tableName, colName, desc);
				columnCount++;
			}
		}
		
		session.close();
		UpdateResult ret = new UpdateResult(tableCount, columnCount);		
		return ret;
	}

	
	
	
	public static void main(String[] args) {
		System.out.println("==== execute ... ====");
		System.out.println("building dict folder path ...");
		String folder = ClassLoader.getSystemResource("jsons/").getPath();
		System.out.println(folder);
		
		
		List<DatabaseItem> dbs =  ReadDict.loadInFolder(folder);
		System.out.println("==== read c++ header file folder ====");
		System.out.println(folder);
		
		System.out.println(args.length);
		
		String ip = args[0];
		String user = args[1];
		String pwd = args[2];
		
		System.out.println("==== database information ====");
		System.out.println(ip);
		System.out.println(user);
		System.out.println(pwd);
		
		System.out.println("==== update description ====");
		int fileCount = 0;
		
	
		for(DatabaseItem db : dbs) {
			UpdateResult ret = updateDesc(db, ip, user, pwd);
			fileCount++;
			
			System.out.println("updated table:" + ret.getTableCount());
			System.out.println("updated column:" + ret.getColumnCount());
		}
		
		System.out.println("==== update finished ====");
		System.out.println("load file: " + fileCount);
		
	}
}

@Data
class UpdateResult {		
	
	public UpdateResult() {
		
	}
	
	public UpdateResult(int tableCount, int columnCount) {
		this.tableCount = tableCount;
		this.columnCount = columnCount;
	}
	
	private int tableCount;
	private int columnCount;
}
