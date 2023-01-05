require('harry.pluginsetup')
require('harry.plugins.telescope')
require('harry.plugins.treesitter')
require('harry.plugins.nvim-tree')
require('harry.plugins.lsp')

vim.opt.tabstop = 4
vim.opt.shiftwidth = 4
vim.opt.softtabstop = 4

vim.opt.ignorecase = true -- ignore case when searching
vim.opt.smartcase = true -- ignore case unless there is a capital letter in the search

--vim code for this is :set ignorecase

vim.opt.iskeyword:append('-') --consider string-string as a word
vim.opt.iskeyword:append('_') --consider string_string as a word
vim.opt.iskeyword:append('.') --consider string/string as a word

vim.o.termguicolors = true -- enable 24-bit RGB colors
vim.cmd [[let g:gruvbox_contrast_dark = 'hard']] -- vim.cmd [[ ]] will run vim code in lua file.
vim.cmd [[colorscheme gruvbox]] -- set colorscheme, gruvbox is from morhetz/gruvbox

vim.o.breakindent = true -- wrap text with indent
vim.o.undofile = true -- enable undo
vim.o.mouse = 'a' -- enable mouse

vim.keymap.set('n', '[d', vim.diagnostic.goto_prev, { noremap = true, silent = true })
vim.keymap.set('n', ']d', vim.diagnostic.goto_next, { noremap = true, silent = true })
vim.keymap.set('n', '<leader>q', vim.diagnostic.setloclist, { noremap = true, silent = true })
vim.keymap.set('n', '<leader>l', vim.diagnostic.open_float, { noremap = true, silent = true })

-- See :help lualine.txt
-- dependent on lualine plugin
require('lualine').setup {
  options = {
	theme = 'gruvbox',
	icons_enabled = false,
	component_separators = '|',
	section_separators = '',
  },
}

require('indent_blankline').setup {
	char = '┊',
	show_trailing_blankline_indent = false,
}

require("mason").setup({
    ui = {
        icons = {
            package_installed = "✓",
            package_pending = "➜",
            package_uninstalled = "✗"
        }
    }
})
