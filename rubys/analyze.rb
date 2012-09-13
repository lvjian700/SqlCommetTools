#encoding: GBK
require 'rubygems'
require 'json'
##read property line##
#\w*;\s*\/{2}[^x00-xff]*

##read property
#(\w*);\s*(\/{2}[^x00-xff]*)
##ready desc

##match all columns
# /(\w*);\s*\/{2}([^x00-xff]*)\n/

##match struct
# /^struct\s+(\w+)/
STDOUT.set_encoding "gbk"

#define *.h to database mapping
DB = {"ulccommondefine" => "dyulc30_hw",
        "ulctaskdefine" => "dyulc30_hw",
        "ulcexdefine" => "dyulc30_hw"}
puts "*.h file to database name mapping:"
p DB

def readTables(file)
    tables = Array.new
    cols = Hash.new
    table = nil
    tableCols = nil

    file.each_line do |line| 
        structMatch = /^struct\s+(\w+)/.match(line)

        if(structMatch != nil)
            # tables
            puts "Current line is struct line, reading table name...."

            tableMatched = structMatch[1]
            puts "struct matched: #{tableMatched}"

            puts "remove prefix"
            tableName = nil
            if tableMatched.index("SDY") == 0 
                tableName = tableMatched[3..tableMatched.length]
            else
                tableName = tableMatched
            end

            puts "real table name: #{tableName} "      

            puts 'rebuild table data struct, put value to Hash...'
            table = Hash.new
            table["name"] = tableName   
            tables<<table   

            puts "rebuild colums Array on table..."
            tableCols = Array.new
            table['columns'] = tableCols

            p table
            puts "finish ...."

        else# end reading table
            # column item      
            target = /(\w*);\s*\/{2}([^x00-xff]*)\n/.match(line)

            if target != nil 
                puts "Current line is property line, reading column & desc ..."

                colItem = Hash.new

                puts "building column & desc ..."
                column = target[1]
                desc = target[2]
                colItem["column"] = column
                colItem["desc"] = desc
                p colItem

                puts "put value to tableCols!"
                tableCols<<colItem
            end
            # end reading columns            
        end
        # end reading table & columns

    end
    # end reading each line of file

    return tables
end # end readTables method


def readDBHash(fileName)

    dbName =  fileName[2..fileName.length]  
    dbHash = Hash.new
    dbHash['name'] = DB[dbName]

    return dbHash
end


def writeJson(json, filePath)
    puts "write json to: #{filePath}"

    jsonFile = File.new(filePath, "w")  
    jsonFile.puts json
    jsonFile.close 

    puts "write finished..."
end

path = File.dirname(__FILE__) + "/../headers"
puts "C++ *.h file folder path: #{path}"

baseFilePath = File.dirname(__FILE__) + "/../src/jsons/"
puts "json folder path: #{baseFilePath}"


Dir.glob("#{path}/*.h") { |entry| 
    fileHash = Hash.new

    f = File.open("./#{entry}")
    fileName = File.basename(f, ".h")
    fileHash['database'] = readDBHash fileName

    fileHash['database']['tables'] = readTables(f)

    json = fileHash.to_json
    gbk = Iconv.iconv("GBK","UTF-8", json)

    jsonFilePath = baseFilePath + fileName + ".json"
    writeJson(gbk, jsonFilePath )
}
#file = File.open("#{folderPath}/dyulccommondefine.h", "r")

#p ReadCommets(file)
