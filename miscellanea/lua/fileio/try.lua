function print_table(t)
	for k,v in pairs(t) do
		print(k,v)
	end
end

local ln = '(a(v)b)/(12e)' 
print(string.match(ln, '[{(](.+)[)}]/[{(](.+)[)}]'))

function scandir()
    local i, t, popen = 0, {}, io.popen
    local pfile = popen('find . -type f')
    for filename in pfile:lines() do
        i = i + 1
        t[i] = filename
    end
    pfile:close()
    return t
end

local t = scandir()
for k,v in pairs(t) do
		print(k,v)
end

for k,v in pairs(t) do
	if string.match(v, './.*.c$') then
		print(v)
	end
end

print(io.popen("pwd"):read())

local crescendum = {1}
function inc() 
	return {2,3}
end
print_table(crescendum)
print("after inc()")
crescendum=inc()
print_table(crescendum)
print("print a")
local a = 1
function inc2()
	print(a)
end
