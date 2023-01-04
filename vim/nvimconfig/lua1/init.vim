:set number
:colorscheme koehler
let g:copilot_filetypes={
	\'cpp': v:false,
	\ }

lua <<EOF
--print("Let us be productive!")
print("Gaudeamus igitur, iuvenes dum sumus!")
EOF

lua require ('harry') -- requires the init.lua file in the lua directory
