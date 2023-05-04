-- Everything in lua is a table
-- Here are some didactic examples

hello ={"Hello", "World", "!",} 
print(table.concat(hello, " "))  -- Simple way to print non nested table
nested = {1,2,3,{4,5,6}, {"one", {9,8},{}} ,"two"}  -- Tables can be nested indefinitely

-- Iterate through table
function ptable(t)
		for k,v in pairs(t) do
				print(k,v)
		end
end

function pnestedTable(t)
	local res = "{"
	for j,i in pairs(t) do
		if type(i)=='table' then
			res = res .. "," .. pnestedTable(i)  -- .. is string concatenation operator 
		else 
			if j == 1 then -- if is followed by then
				res = res  .. i
			else 
				res = res  .. "," .. i
			end 
		end
	end
	res = res .. "}"
	return res
end

print(pnestedTable(nested))
