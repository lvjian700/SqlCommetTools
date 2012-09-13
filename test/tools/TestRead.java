package tools;

import java.util.List;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import tools.to.DatabaseItem;
import tools.to.TableItem;
import static org.junit.Assert.*;

public class TestRead {
	
	private String path = null;
	private String folder = null;
	@Before 
	public void createPath() {
		path = ClassLoader.getSystemResource("jsons/dyulccommondefine.json").getFile();
		folder = ClassLoader.getSystemResource("jsons/").getPath();
	}
	
	@After
	public void clear() {
		path = null;
		folder = null;
	}

	@Test
	public void readFile() {
		System.out.println(path);
		
		try {
			String json = ReadDict.readFile(path);
			assertNotNull(json);			
			System.out.println(json);
		} catch(Exception e) {
			fail(e.getMessage());
		}
		
	}
	
	@Test
	public void paseJson() {		
		String json = ReadDict.readFile(path);
		assertNotNull(json);
		
		DatabaseItem db = ReadDict.parseJson(json);
		assertNotNull(db);
		
		System.out.println(db.toString());
		
		List<TableItem> tables = db.getTables();
		assertNotNull(tables);
		assertTrue(tables.size() > 0);
	}
	
	@Test
	public void loadFolder() {
		List<DatabaseItem> dbs = ReadDict.loadInFolder(folder);
		assertNotNull(dbs);
		assertEquals(2, dbs.size());
		
	}
}
