ArmoredForce
=======
A military Card Game Server demo



### 构建步骤(Windows)
* 下载[git for windows](http://msysgit.github.io/)	
* 下载[Boost](http://boost.org)，设置其路径为环境变量BOOST_DIR    
* git clone https://github.com/ichenq/ArmoredForce
* 编译premake工具(Toolset/premake)
* 使用premake生成3rdParty下所有依赖库
* 进入Build目录生成Server解决方案(build_vs2012.bat)
	
	
### 目录说明
* 3rdParty	第三方依赖库
* Build		生成项目工程
* common	与客户端的协议   
* Server	服务器源码目录
  + RPC           RPC接口定义
  + SQL           表及存储过程定义
  + DBServer      数据存储服务器
  + CenterServer  中心服务器
  + GameServer    游戏服务器
  + LoginServer   登录服务器
* Run		包含服务器启动配置文件
* Toolset   工具相关
	
