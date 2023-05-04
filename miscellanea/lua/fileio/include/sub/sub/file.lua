function searchForPictureRecursively()
	main_found = false
	picture_files ={}
	prev = "./"
	n_iter = 2
	t =  {}

	function findPictureFiles(all_files)
		local picture_files = {}
		for k, v in pairs(all_files) do
			if string.match(v, "%.png$") 
				or string.match(v, "%.jpg$")
				or string.match(v, "%.jpeg") then
				table.insert(picture_files, v)
			end
		end
		return picture_files
	end 

	function creatlistofFile()
		pfile = io.popen("find ".._G.prev)
		_G.t = {}
		i = 0

		for line in pfile:lines() do
			i = i + 1
			t[i] = line
			print(line)
		end
		-- print(table.concat(t, " "))
		if string.find(table.concat(t, " "), "main") then
			main_found = true	
			picture_files = findPictureFiles(t)
		else 
			if n_iter > 0 then
				prev = prev .. "../"
				n_iter = n_iter - 1  -- lua has no increment operator
				creatlistofFile()
			end
		end
	end

	creatlistofFile()
	if main_found then
		print("main found")
		return picture_files
	else
		return nil
	end 
end

picture_files = searchForPictureRecursively()
-- for k, v in pairs(picture_files) do
-- 		print(k, v)
-- end
