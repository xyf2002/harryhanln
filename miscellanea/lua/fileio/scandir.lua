function hhyh.scandir()
	local i, t, popen = 0, {}, io.popen
	local pfile = popen('find')
	for filename in pfile:lines() do
		i = i + 1
		t[i] = filename
	end
	pfile:close()
	return t
end

