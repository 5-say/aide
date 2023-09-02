
run:
	@echo ""
	@echo "-----------------------------------------"
	@echo "make init  | 初始化项目"
	@echo "-----------------------------------------"
	@echo ""

.PHONY:init
init:
	sh shell/install/docker
	sh shell/install/vscode-extension
	sh shell/install/xmake
