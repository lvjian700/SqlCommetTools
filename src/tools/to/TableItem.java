package tools.to;

import java.util.ArrayList;
import java.util.List;

import lombok.Data;

@Data
public class TableItem {
	private String name = "";
	private List<ColumnItem> columns = new ArrayList<ColumnItem>();
}
