vim.keymap.set('i', '<F3>', '<Esc>:w<CR>:!g++ <C-R>%<CR>', {noremap = true})
vim.keymap.set('n', '<F3>', ':!./a.out<CR>', {noremap = true})
