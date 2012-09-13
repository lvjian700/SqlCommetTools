package tools;


import java.sql.Connection;

import org.junit.Test;

import tools.db.DB;
import tools.db.DBConn;

import static org.junit.Assert.*;
public class DBTest {
	
	@Test
	public void urlTest() {
		String url = DBConn.buildUrl("192.168.1.47", "dyulc30_hw");
		assertNotNull(url);
		
		assertEquals("jdbc:sqlserver://192.168.1.47:1433;DatabaseName=dyulc30_hw",
				url);
	}
	
	@Test
	public void connection() {
		try {
			Connection c = DBConn.getConn("192.168.1.47", "dyulc30_hw", "sa", "1");
			assertNotNull(c);
			c.close();
		} catch(Exception ex) {
			fail("fail to create connection");
		}
	}
	
	@Test
	public void hasTable() {
		Connection c = DBConn.getConn("192.168.1.47", "dyulc30_hw", "sa", "1");
		DB session = DB.open(c, "dyulc30_hw");
		
		boolean hasTable = session.hasTable("ulctaskinfo");
		assertTrue(hasTable);
		
		boolean hasColumn = session.hasColumn("ulctaskinfo", "strname");
		assertTrue(hasColumn);
		
		boolean hasT = session.hasTable("dyuccc");
		assertFalse(hasT);
		
		boolean hasC = session.hasColumn("dyulctaskinfo", "strname233");
		assertFalse(hasC);
		
		session.close();
	}
	
	@Test
	public void desc() {
		Connection c = DBConn.getConn("192.168.1.47", "dyulc30_hw", "sa", "1");
		DB session = DB.open(c, "dyulc30_hw");
		
		session.addDesc("ulctaskinfo", "strname", "这个是名称");
		
		session.close();
	}
}
