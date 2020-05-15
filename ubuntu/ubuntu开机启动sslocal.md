### 在 /etc/systemd/system/下新建shadowsocks.service文件

```shell
里面的内容是

After=network.target
[Service]
Type=simple
User=root
ExecStart=/usr/local/bin/sslocal -s vpsip -p vpsport -k vpspwd
[Install]
WantedBy=multi-user.target
```



### 查看是否开机启动

```shell
systemctl list-unit-files | grep shadowsocks.service
```

