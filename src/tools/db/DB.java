package tools.db;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import lombok.Getter;

public class DB {
	
	private DB() {
		
	}
	
	@Getter
	private String database;
	@Getter
	private Connection conn = null;
	
	public static DB open(Connection conn, String database) {
		DB db = new DB();
		db.conn = conn;
		db.database = database;
		
		return db;
	}
	
	public void addDesc(String table, String column, String desc) {
		String sql = "execute sp_addextendedproperty N\'MS_Description\', \'" + desc + "\', N\'user\', N\'dbo\', N\'table\', N\'"
				+ table + "\', N\'column\', N\'" + column + "\';";
		
		String updateSql = "execute sp_updateextendedproperty N\'MS_Description\', \'" + desc + "\', N\'user\', N\'dbo\', N\'table\', N\'"
			+ table + "\', N\'column\', N\'" + column + "\';";
		
		System.out.println(sql);
		
		PreparedStatement ps = null;
		try {
			ps = conn.prepareStatement(sql);

			ps.execute();
			
		} catch (SQLException e) {
			System.out.println("the my description is exists");
			try {
				ps.close();
				
				ps = conn.prepareStatement(updateSql);
				ps.execute();
			
			} catch (SQLException e1) {
				e1.printStackTrace();
			}			
			
		} finally {
			try {
				ps.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				ps = null;
			}
		}
		
	}
	
	public boolean hasTable(String table) {
		String sql = "select count(id) from dbo.sysobjects where name = ?";
		boolean ret = false;
		
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			ps = conn.prepareStatement(sql);
			ps.setString(1, table);
			rs = ps.executeQuery();
			if(rs.next()) {
				int exists = rs.getInt(1);
				ret = exists == 1;
			}
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				ps.close();
				rs.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				ps = null;
				rs = null;
			}
		}
		
		return ret;
	}
	
	
	//select col_length('ulctaskinfo', 'strname');
	public boolean hasColumn(String table, String column) {
		String sql = "select col_length(?, ?)";
		boolean ret = false;
		
		PreparedStatement ps = null;
		ResultSet rs = null;
		try {
			ps = conn.prepareStatement(sql);
			ps.setString(1, table);
			ps.setString(2, column);
			rs = ps.executeQuery();
			if(rs.next()) {
				Object obj = rs.getObject(1);
				ret = obj != null;
			}
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				ps.close();
				rs.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				ps = null;
				rs = null;
			}
		}
		
		return ret;
	}
	
	
	
	public void close() {
		try {
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			this.database = null;
		}
	}
}
