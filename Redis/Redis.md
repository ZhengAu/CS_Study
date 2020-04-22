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
>
> flushdb //清除当前库
>
> flushall //清除全部库

## 5. 数据类型

`Redis` 支持五种数据类型：

- String 字符串 [String](https://www.runoob.com/redis/redis-strings.html)
- Hash 哈希 [Hash](https://www.runoob.com/redis/redis-hashes.html)
- List 列表 [List](https://www.runoob.com/redis/redis-lists.html)
- Set 集合 [Set](https://www.runoob.com/redis/redis-sets.html)
- Sorted Set (zset) 有序集合 [ZSet](https://www.runoob.com/redis/redis-sorted-sets.html)

> help @type  //查看上述数据类型的指令

## 6.Redis键

> keys *  //查看全部key
>
> keys k? //查看有k开头的键
>
> exists key  //判断某个key是否存在
>
> select [0-15]  //选择某个库
>
> move key db  //移动某个key到某个库
>
> ttl key //查看key还有多少秒过期，-1表永不过期，-2表示已过期
>
> expire key 秒   //为给定的key设置过期时间
>
> type key //查看key是什么类型

## 7.String

> set/get/del/append/strlen
>
> incr/decr key  //递增递减某key，要有数字才能进行
>
> incrby/decrby  key number //每次增加减少number
>
> getrange key from to //获取key的from到to的子字符串
>
> setrange key index newString //设置key从index开始的子字符串
>
> setex(set with expire) key second value //设置有过期时间的key
>
> setnx(set if not exist) key value // key不存在才设置
>
> mset key value [key value ...]
>
> mget key [key ...]
>
> msetnx key value [key value ...] //有一组存在都不能设置

## 8. List

> lpush/rpush/ key value [value ...]
>
> lrange key start end   //获取范围，包括start, end，end为-1的话表示从start到最后
>
> lpop/rpop key
>
> lindex key index //获取index位
>
> llen key //key的值个数
>
> lrem key count value //删除key下count个value值，value存在则删除成功
>
> ltrim key start end //截取指定范围的值后再度赋值给key
>
> rpoplpush key1 key2 //把key1中的右边pop出，放入key2的左边
>
> lset key index value //重新设置index的值

## 9. Set

> sadd key value [value ...]
>
> smembers key
>
> sismember key value //判断是否为key中元素
>
> scard key //个数
>
> spop key [count]  //随机出栈count个，默认一个
>
> srem key member [member ...] //删除元素
>
> srandmember key [count] //随机选几个数，默认为1，不影响原set
>
> smove source destination member //从souce中移动member元素到destination中

数学集合类：

> sdiff key1 [key2]  //差集，在key1不在key2
>
> sinter key1 [key2] //交集
>
> sunion key1 [key2] //合集

## 10. Hash

KV模式不变，但V是一个键值对。

> hset key field value
>
> hget key field
>
> hmset key field value [field value ...]
>
> hmget key field [field ...]
>
> hgetall key  //得到全部field和对应的value
>
> hdel key field
>
> hlen key
>
> hexists key field
>
> hkeys key
>
> hvals key
>
> hincrby key field value //key对于field添加value
>
> hincrbyfloat key field value //key对于field添加value，value可以是小数
>
> hsetnx key field value //field不存在key中才添加

## 11. Zset

`Redis` 有序集合和集合，都是string类型元素的集合，且不允许重复的成员。

不同的是每个元素都会关联一个double类型的分数。

`redis` 正是通过分数来为集合中的成员进行从小到大的排序。

有序集合的成员是唯一的，但分数（score）却可以重复。

集合是通过哈希表实现的，所以添加，删除，查找的复杂度都是O(1)。集合中最大的成员数是(2^32)-1。（每个集合可存储40多亿个成员）

> zadd key score member [score member ...]
>
> zrange key start end
>
> zrangebysocre key min max [withscores] [limit offset count]
>
> zrem key member [member ...]
>
> zcard key //个数
>
> zcount key min max //统计在min和max之间的个数
>
> zrank key member //获取下标，从0开始
>
> zscore key member //获取member对应的score
>
> zrevrank key member //逆序获得下标值
>
> zrevrange key start end //从start到end逆序获得值
>
> zrevrangebyscore key max min //从max到min获取

## 12. redis.conf

## 13. 持久化

### 13.1 RDB(Redis DataBase)

配置里面可以配置多久保存一次数据。

> save 900 1
> save 300 5
> save 60 10000

RDB出了问题，可以使用 `redis-check-dump --fix rdbfilename` 进行修复。

### 13.2 AOF(Append Only File)

`AOF` 持久化默认是关闭的。

对于set之类的操作，每秒都会自动记录到 `aof` 文件中，默认为 `appendonly.aof`；
对于get之类的操作，`aof` 不会记录。

注意：AOF 和 RDB 持久化是可以在不出错的情况下共存的。如果 AOF 存在，则会优先加载 `AOF`。

AOF出了问题，可以使用 `redis-check-aof --fix aoffilename` 进行修复。
