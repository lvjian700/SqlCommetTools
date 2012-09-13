###说明
---
SqlCommetTools是为公司C/S研发做的, SqlServer注释同步工具. 将C++头文件中的注释同步到SQL Server表中.

###程序结构说明
---

headers/*.h 为待处理的C++头文件, 该文件中映射了数据库表结构. 并且每个属性后面都有单行注释	

ruby/analyze.rb 程序为C++头文件分析程序, 分析C++中的语法, 提取Struts名称, 字段名称-注释. 并且生成相应的json文件.	

src/ 目录下是Java程序, 用来分析ruby生成的json数据, 将注释更新到数据库中.	

###环境说明
---

* ruby-1.9.2
* JDK 1.6
* Ant 1.8 	
* Sql Server 2005 (其他Sql Server 版本未测试)

###使用说明
---

1.clone项目	

	git://github.com/lvjian700/SqlCommetTools.git

2.安装ruby依赖	

	cd SqlCommetTools/ruby
	bundle install	

3. 运行Ant脚本

	cd SqlCommetTools
	ant	


