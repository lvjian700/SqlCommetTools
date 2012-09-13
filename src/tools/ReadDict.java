package	tools;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import tools.to.ColumnItem;
import tools.to.DatabaseItem;
import tools.to.TableItem;
import flexjson.JSONDeserializer;

public class ReadDict {
	
	public static List<DatabaseItem> loadInFolder(String folderPath) {
		System.out.println("-- loading folder content from path ...");
		System.out.println(folderPath);
		
		File dir = new File(folderPath);
		String[] list = dir.list();
		System.out.println("the folder is exists? ");
		System.out.println(dir.exists());
		
		
		List<DatabaseItem> dbs = new ArrayList<DatabaseItem>();
		
		System.out.println("read all file paths in the folder...");
		for(String name : list) {
			String filePath = folderPath + name;
			
			System.out.print("--");
			System.out.println(filePath);
			
			DatabaseItem db = loadJson(filePath);
			dbs.add(db);
		}
		
		return dbs;
	}
	
	public static DatabaseItem loadJson(String filePath) {
		String json = readFile(filePath);
		assert json != null;
		
		DatabaseItem db = parseJson(json);
		
		return db;
	}
	
	@SuppressWarnings("rawtypes")
	static DatabaseItem parseJson(String json) {
		System.out.println("-- parsing json...");
		Map map = new JSONDeserializer<Map>()
			.use("database.tables", ArrayList.class)
			.use("database.tables.columns", ArrayList.class)
			.deserialize(json);
		
		DatabaseItem dbItem = new DatabaseItem();
		
		Map dbMap = (Map)map.get("database");
		String name = dbMap.get("name").toString();
		dbItem.setName(name);
		
		List<TableItem> tables = new ArrayList<TableItem>();
		dbItem.setTables(tables);
		
		List tableList = (List)dbMap.get("tables");		
		

		System.out.println("table count: " + tableList.size());
		for(int i = 0; i < tableList.size(); i ++) {
			TableItem tableItem = new TableItem();
			tables.add(tableItem);
			
			Object table = tableList.get(i);
			if(table instanceof TableItem) {
				continue;
			}
			
			Map tableMap = (Map)table;
			
			String tableName = tableMap.get("name").toString();
			tableItem.setName(tableName);
			
			List<ColumnItem> columns = new ArrayList<ColumnItem>();
			tableItem.setColumns(columns);
			
			List columnList = (List)tableMap.get("columns");
			for(int n = 0; n < columnList.size(); n++) {
				Object col = columnList.get(n);
				Map colMap = (Map)col;
				String column = colMap.get("column").toString();
				String desc = colMap.get("desc").toString();
				
				ColumnItem colItem = new ColumnItem();
				colItem.setColumn(column);
				colItem.setDesc(desc);
				columns.add(colItem);				
			}
			
			
		}
		
		return dbItem;
	}
	
	static String readFile(String filePath) {
		System.out.println("-- read file from path...");
		System.out.println(filePath);
        BufferedReader reader = null;
        
        StringBuffer buffer = new StringBuffer();
        try {
            reader = new BufferedReader(new InputStreamReader(new FileInputStream(filePath), "gbk"));
            String tempString = null;
            
            // 一次读入一行，直到读入null为文件结束
            while ((tempString = reader.readLine()) != null) {
                // 显示行号
            	buffer.append(tempString);            
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (reader != null) {
                try {
                    reader.close();
                } catch (IOException e1) {
                }
            }
        }
        
        return buffer.toString();
	}
}
