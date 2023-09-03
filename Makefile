
run:
	@echo ""
	@echo "-----------------------------------------"
	@echo "make init  | 初始化项目"
	@echo "-----------------------------------------"
	@echo "make r     | 编译并运行项目"
	@echo "-----------------------------------------"
	@echo ""

.PHONY:init
init:
	sh shell/install/docker
	sh shell/install/vscode-extension
	sh shell/install/cpp
	sh shell/install/clangd
	sh shell/install/codelldb
	sh shell/install/xmake

.PHONY:r
r:
	xmake --root
	cp build/linux/x86_64/release/aide aide
