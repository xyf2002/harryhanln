# Note for Using vim/nvim

## Useful Key mapping/ short cuts

## Useful commands

`:scriptnames` shows all scripts the vim has loaded.
``

## Commands for Ultisnips


`packer` provides the following commands after you've run and configured `packer` with `require('packer').startup(...)`:

```
-- You must run this or `PackerSync` whenever you make changes to your plugin configuration
-- Regenerate compiled loader file
:PackerCompile

-- Remove any disabled or unused plugins
:PackerClean

-- Clean, then install missing plugins
:PackerInstall

-- Clean, then update and install plugins
-- supports the `--preview` flag as an optional first argument to preview updates
:PackerUpdate

-- Perform `PackerUpdate` and then `PackerCompile`
-- supports the `--preview` flag as an optional first argument to preview updates
:PackerSync

-- Show list of installed plugins
:PackerStatus

-- Loads opt plugin immediately
:PackerLoad completion-nvim ale
```
