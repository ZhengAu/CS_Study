# Redis

## 1. 简介

`Redis` 是完全开源免费的，遵守BSD协议，是一个高性能的key-value数据库。

`Redis`与其他 key - value 缓存产品有以下三个特点：

- Redis 支持数据的持久化，可以将内存中的数据保存在磁盘中，重启的时候可以再次加载进行使用。
- Redis 不仅仅支持简单的 key - value 类型的数据，同时还提供 list, set, zset, hash 等数据结构的存储。
- Redis 支持数据的备份，即 master - slave 模式的数据备份。

## 2. 优势

- 性能极高 - Redis 能读的熟读是110000次/s，写的速度是81000次/s。
- 丰富的数据类型 - Redis支持二进制案例的 Strings, Lists, Hashes, Sets 及 Ordered Sets 数据类型操作。
- 原子 - Redis的所有操作都是原子性的，意思就是要么成功执行要么失败完全不执行。单个操作是原子性的。多个操作也支持事务，即原子性，通过 MULTI 和 EXEC 指令包起来。
- 丰富的特性 - Redis还支持 publish/subscribe，通知，key过期等等特性。

## 3. 配置

`Redis` 的配置文件位于 `Redis` 安装目录下，文件名为 `redis.conf` （Windows 下为 `redis.windows.conf`）。

可以通过 `config` 命令查看或设置配置项

> config get *  //查看所有配置
>
> config get config_setting_name //查看某项配置
>
> config set config_setting_name new_config_value //设置某项配置

具体可查看 [Redis配置](https://www.runoob.com/redis/redis-conf.html)

## 4. Redis命令

`Redis` 命令用于在 redis 服务上执行操作。

> redis-cli [ -h host -p port [-a passpord] ] // 连接
>
> ping //检测redis服务是否启动

## 5. 数据类型

`Redis` 支持五种数据类型：

- String 字符串 [String](https://www.runoob.com/redis/redis-strings.html)
- Hash 哈希 [Hash](https://www.runoob.com/redis/redis-hashes.html)
- List 列表 [List](https://www.runoob.com/redis/redis-lists.html)
- Set 集合 [Set](https://www.runoob.com/redis/redis-sets.html)
- Sorted Set (zset) 有序集合 [ZSet](https://www.runoob.com/redis/redis-sorted-sets.html)

> help @type  //查看上述数据类型的指令
