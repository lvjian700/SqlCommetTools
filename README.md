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

3.运行Ant脚本

	cd SqlCommetTools
	ant	

###核心代码说明
---

####使用ruby分析C++程序语法

1.原理	

1. 逐行读取C++源码文件
2. 使用正则表达式匹配Struct, 属性, 注释	

2.ruby中逐行读取文件

	File.open(File.dirname(__FILE__) + "/../headers/dyulctaskdefine.h").each_line do |line |
		# do something....
	end	

3.使用正则表达式匹配Struct,属性,注释	

	File.open(File.dirname(__FILE__) + "/../headers/dyulctaskdefine.h").each_line do |line |
		#match Struct
		structMatch = /^struct\s+(\w+)/.match(line)
		structName  = structMatch[1]

		#match 属性, 注释
		propMatch = /(\w*);\s*\/{2}([^x00-xff]*)\n/.match(line)
		propName = propMatch[1]
		propComment = propMatch[2]
	end	

####如何使用sql语句修改数据库注释	

	--表及字段描述信息处理示例

	--创建表
	create table 表(a1 varchar(10),a2 char(2))

	--为表添加描述信息
	EXECUTE sp_addextendedproperty N'MS_Description', '人员信息表', N'user', N'dbo', N'table', N'表', NULL, NULL

	--为字段a1添加描述信息
	EXECUTE sp_addextendedproperty N'MS_Description', '姓名', N'user', N'dbo', N'table', N'表', N'column', N'a1'

	--为字段a2添加描述信息
	EXECUTE sp_addextendedproperty N'MS_Description', '性别', N'user', N'dbo', N'table', N'表', N'column', N'a2'

	--更新表中列a1的描述属性：
	EXEC sp_updateextendedproperty 'MS_Description','字段1','user',dbo,'table','表','column',a1

	--显示表的描述属性
	SELECT   *
	FROM   ::fn_listextendedproperty (NULL, 'user', 'dbo', 'table', '表', 'column', NULL)

	--删除表中列a1的描述属性：
	EXEC sp_dropextendedproperty 'MS_Description','user',dbo,'table','表','column',a1

	--删除测试
	drop table 表	





