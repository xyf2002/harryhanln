require('harry')
local filename = vim.fn.expand('%')

local function mysplit (inputstr, sep)
	if sep == nil then
		sep = "%s"
	end
	local t={}
	for str in string.gmatch(inputstr, "([^"..sep.."]+)") do
		table.insert(t, str)
	end
	return t
end
local str = mysplit(filename, ".")

local ft = str[2] -- recall in lua the beginning of the list starts with 1. 
print(ft) -- print the file type
