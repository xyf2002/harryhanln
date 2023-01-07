:set number
:set relativenumber
:colorscheme koehler
:filetype on
let mapleader = " "

let g:copilot_filetypes={ 
	\'cpp': v:false,
	\ }

"let g:copilot_enable = 0 

:map <F5> <Esc>:Copilot disable<CR>
:map \<F5> <Esc>:Copilot enable<CR> 

:imap <F2> <Esc>:w<CR>:!g++ <C-R>%<CR>
:map <F2> <Esc>:w<CR>:!g++ <C-R>%<CR>
:map <F3> <Esc>:!./a.out<CR>
:map <leader>e :NvimTreeToggle<CR>
:map <C-Down> <C-d>
:map <C-Up> <C-u>
:map ppp <Esc>:w<CR>:!python3 <C-R>%<CR>
:imap <silent><script><expr> <C-J> copilot#Accept("\<CR>")
let g:copilot_no_tab_map = v:true
lua <<EOF
--print("Let us be productive!")
print("Gaudeamus igitur, iuvenes dum sumus!")
EOF

lua require ('harry') -- requires the init.lua file in the lua directory

let g:gruvbox_contrast_dark = "hard"
