local lspconfig = require("lspconfig")

lspconfig.clangd.setup({
	capabilities = {
		offsetEncoding = { "utf-16" },
	},
})
