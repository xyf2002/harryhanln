function refactoredSearch(findMain, findPictureDir, pictureDirectoryName)
  -- If find main flag is true, find all the picture fill that share the parent directory of the main file. If the main file can not be found in current directory, it will find it recursely in the parent directory (maximum recursion = 4). If multiple main file exist, it will find the main file closest to current directory
  -- If find picture directory flag is true, find all the picture file that are in the directory pictureDirectoryName. If pictureDirectoryName is not found in the current directory, the function will try to find it in parent directory. Maximum traceback = 4. if no pictureDirectoryName is found, it will ignore this flag.
	-- Default value for findMain = false, findPictureDir = false, pictureDirectoryName = "include"
	-- if findMain and findPictureDir are both false, it will find all the picture file in the current directory
	-- true for main take precedence over true for picture directory
  local main_found = false
  local searchDirectory = ""
  local pictureDirectoryName = pictureDirectoryName or "include"
  local pictureDirectoryFound = false
  local findMain = findMain or false
  local findPictureDir = findPictureDir or false
  local searchDirectory
	local c

  local function existFile(filename)
    local filename = filename or "include"
    local iter = 4
    local prev = "./"

    ::nextRecursive::
    include = io.popen("find " .. prev .. " ")

    for line in include:lines() do
      line = line .. "/"
      if string.find(line, "/" .. filename) then return true, line end
    end
    include:close()

    if iter > 0 then
      iter = iter - 1
      prev = prev .. "../"
      goto nextRecursive
    else
      return false, filename .. " Not found"
    end
  end

  local function s_findAllPictureFiles(directory)
    local res = {}
    local function s_isItPicture(filename)
      v = filename
      if string.match(v, "%.png$") or string.match(v, "%.jpg$") or
          string.match(v, "%.jpeg$") or string.match(v, "%.pdf$") then
        return true
      end
      return false
    end

    local pfile = io.popen("find " .. directory)
    for line in pfile:lines() do
      if s_isItPicture(line) then table.insert(res, line) end
    end
    if #res > 0 then
      return res
    else
      return {"No Picture Found"}
    end
  end
	
	searchDirectory = "./"

  if findMain then
    main_found, bufdir = existFile("main")
    if main_found then _, _, c = string.find(bufdir, "(.*)main.*$") end
    searchDirectory = c
  elseif findPictureDir then
    pictureDirectoryFound, bufdir = existFile(pictureDirectoryName)
    if pictureDirectoryFound then
      searchDirectory = bufdir
    end
  else
    searchDirectory = "./"
  end

  return s_findAllPictureFiles(searchDirectory)
end

pictureFound = refactoredSearch(true, true, "")
for k, v in pairs(pictureFound) do print(k, v) end
