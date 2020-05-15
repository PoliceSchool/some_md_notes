1. 将身份切换为"root"用户，因为普通用户会提示没有权限，但是使用"sudo"命令的话又有其他问题，将身份切换为"root"用户则安装顺利

2. 使用以下命令安装v2ray客户端

   ```shell
   bash <(curl -L -s https://install.direct/go.sh)
   ```

3. 安装成功后会生成```/etc/v2ray/config.json```文件，将这个文件备份为```/etc/v2ray/config.json.backup```

4. 我在windows系统安装了v2ray的客户端程序```v2rayN```，使用```v2rayN```可以导出客户端的配置文件，将这个配置文件移动到ubuntu的```/etc/v2ray/```目录下，并且重名为```config.json```即可

5. 然后执行以下命令

   ```shell
   service v2ray stop
   service v2ray start
   service v2ray status
   
   ##输出结果
   ● v2ray.service - V2Ray - A unified platform for anti-censorship
      Loaded: loaded (/etc/systemd/system/v2ray.service; enabled; vendor preset: enabled)
      Active: active (running) since Wed 2020-05-13 12:07:40 CST; 43s ago
        Docs: https://v2ray.com
              https://guide.v2fly.org
    Main PID: 9709 (v2ray)
       Tasks: 13 (limit: 4915)
      CGroup: /system.slice/v2ray.service
              └─9709 /usr/bin/v2ray/v2ray -config /etc/v2ray/config.json
   
   5月 13 12:07:40 jimson systemd[1]: Started V2Ray - A unified platform for anti-censorship.
   5月 13 12:07:40 jimson v2ray[9709]: V2Ray 4.23.1 (V2Fly, a community-driven edition of V2Ray.) Custom (go
   5月 13 12:07:40 jimson v2ray[9709]: A unified platform for anti-censorship.
   5月 13 12:07:40 jimson v2ray[9709]: 2020/05/13 12:07:40 [Info] v2ray.com/core/common/platform/ctlcmd: <v2
   5月 13 12:07:40 jimson v2ray[9709]: v2ctl> Read config:  /etc/v2ray/config.json
   5月 13 12:07:40 jimson v2ray[9709]: 2020/05/13 12:07:40 [Warning] v2ray.com/core: V2Ray 4.23.1 starte
   ```

6. chrome浏览器安装```Proxy SwitchOmega```插件，配置代理服务器地址为```127.0.0.1```，端口为```10808```即可，然后访问网络时切换为自动切换即可。