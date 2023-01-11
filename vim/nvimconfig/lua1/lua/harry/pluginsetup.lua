return require('packer').startup(function(use)
	use "wbthomason/packer.nvim"
	use "nvim-lua/plenary.nvim"
	use({"nvim-telescope/telescope.nvim", requires = {{"nvim-lua/popup.nvim"}}})
	use {
		"nvim-treesitter/nvim-treesitter", 
		run = function()
			pcall(require("nvim-treesitter.install").update{ with_sync = true})
		end,
	}
	use {
		'nvim-treesitter/nvim-treesitter-textobjects',
		after = 'nvim-treesitter',
	}

	-- Git Related Plugins
	use "tpope/vim-fugitive"
	use "tpope/vim-rhubarb"
	use "lewis6991/gitsigns.nvim"

	use "navarasu/onedark.nvim"
	use "morhetz/gruvbox"
	use "nvim-lualine/lualine.nvim"
	use "lukas-reineke/indent-blankline.nvim"
	use "tpope/vim-surround" 
	use {
		"nvim-tree/nvim-tree.lua",
		requires = {
			'nvim-tree/nvim-web-devicons',
		}
	}


	-- LSP Related Plugins
	use{
		"neovim/nvim-lspconfig",
		requires = {
			'williamboman/mason.nvim',
			'williamboman/mason-lspconfig.nvim',

			'j-hui/fidget.nvim',

			'folke/neodev.nvim',
		}
	}
	
	use { -- Autocompletion
		'hrsh7th/nvim-cmp',
		requires = { 'hrsh7th/cmp-nvim-lsp', 'L3MON4D3/LuaSnip', 'saadparwaiz1/cmp_luasnip' },
	}
end)

