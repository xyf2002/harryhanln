return require('packer').startup(function(use)
	use "nvim-lua/plenary.nvim"
	use({"nvim-telescope/telescope.nvim", requires = {{"nvim-lua/popup.nvim"}}})
end)	
