/*
 * @Author: Chacha
 * @Date: 2022-03-19 17:01:38
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-11 10:57:05
 */

/**
 * 双指针法
 *
 * 金融分析师负责以一系列为代表的有利可图股票投资组合。每个的数组中的项目代表相应股票的年利润。
 * 分析师收集了所有达到目标利润的不同对股票。不同的对是至少不同的对一个元素。给定利润数组，
 * 找到不同一对股票的数量，其中每对的总和利润与目标利润完全相等。
 *
 * 示例 1：
 * 输入：
 * stocksProfit = [5, 7, 9, 13, 11, 6, 6, 3, 31]
 * target = 12 (利润目标)
 *
 * 输出：3
 * 因为存在 3 对股票组合的利润是 12：[5, 7]，[3, 9]，[6， 6]
 *
 */

function stockPairs(stocksProfit, target) {
    let pairs = 0;
    let low = 0,
        high = stocksProfit.length - 1;

    // 将数组排序
    stocksProfit.sort((a, b) => a - b);

    while (low < high) {
        if (stocksProfit[low] + stocksProfit[high] === target) {
            // 移除重复元素
            while (low < high && stocksProfit[low] === stocksProfit[low + 1]) {
                low++;
            }
            while (
                low < high &&
                stocksProfit[high] === stocksProfit[high - 1]
            ) {
                high--;
            }

            pairs += 1;

            low++;
            high--;
        } else if (stocksProfit[low] + stocksProfit[high] < target) {
            low++;
        } else {
            high--;
        }
    }

    return pairs;
}

console.log("====================================");
console.log(stockPairs([5, 6, 5, 7, 7, 8], 13)); // 输出 2
console.log("====================================");

console.log("====================================");
console.log(stockPairs([5, 7, 9, 13, 11, 6, 6, 3, 31], 12)); // 输出 3
console.log("====================================");
