local builtin = require('telescope.builtin')
require 'telescope'.setup {
  defaults = {
	file_ignore_patterns = { "node_modules", ".git" },
	mappings = {
	  i = {
		["<C-j>"] = builtin.move_selection_next,
		["<C-k>"] = builtin.move_selection_previous,
	  },
	},
  },
  pickers = {
	buffers = {
	  sort_lastused = true,
	  theme = "dropdown",
	  previewer = false,
	  mappings = {
		i = {
		  ["<C-d>"] = "delete_buffer",
		},
		n = {
		  ["<C-d>"] = "delete_buffer",
		},
	  },
	},
  },
}
pcall(require('telescope').load_extension, 'fzf')
vim.keymap.set('n', '<leader>?', builtin.oldfiles, {desc = '[?] Find old files'})
vim.keymap.set('n', '<leader><space>', builtin.buffers, {desc = '[?] Find Existing buffers'})
vim.keymap.set('n',  '<leader>/', function()
	builtin.current_buffer_fuzzy_find ( 
	require('telescope.themes').get_dropdown {
		winblend = 10,
		previewer = false,
		})
end, {desc = '[/] Fuzzily search in current buffer'})

vim.keymap.set('n', '<leader>ff', builtin.find_files, {desc = '[F]ind [F]iles'})
vim.keymap.set('n', '<leader>fg', builtin.live_grep, {desc = '[F]ind [G]rep'})
vim.keymap.set('n', '<leader>fb', builtin.buffers, {desc = '[F]ind [B]uffers'})
vim.keymap.set('n', '<leader>fh', builtin.help_tags, {desc = '[F]ind [H]elp'})
