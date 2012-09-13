package tools.to;

import java.util.ArrayList;
import java.util.List;

import lombok.Data;

@Data
public class DatabaseItem {
	
	private String name = "";
	private List<TableItem> tables = new ArrayList<TableItem>();
}
