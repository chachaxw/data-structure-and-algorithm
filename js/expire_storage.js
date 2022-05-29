/*
 * @Author: Chacha
 * @Date: 2022-05-29 11:19:24
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-05-29 13:18:34
 */

/**
 * Expire storage，支持过期时间的 localStorage
 */

class ExpireStorage {
    prefix = "Chacha";

    tag = "|Chacha|";

    defaultTime = Date.now() + 24 * 60 * 60 * 31 * 1000; // 默认时长1个月

    constructor(prefix, tag) {
        this.prefix = prefix;
        this.tag = tag;
    }

    setItem(key, value, time) {
        key = `${this.prefix}${key}`;
        time = time ? new Date(time).getTime() : this.defaultTime;

        // 构造一个形如 1646094676134|Chacha|"Hello World" 结构的字符串
        window.localStorage.setItem(
            key,
            `${time}${this.tag}${JSON.stringify(value)}`
        );
    }

    getItem(key) {
        key = `${this.prefix}${key}`;
        let value = window.localStorage.getItem(key);

        if (value) {
            let index = value.indexOf(this.tag);
            let time = +value.slice(0, index);

            // 判断时间是否已过期
            if (time > Date.now()) {
                value = JSON.parse(value.slice(index + this.tag.length));
            } else {
                value = null;
                window.localStorage.removeItem(key);
            }
        }

        return value;
    }
}
