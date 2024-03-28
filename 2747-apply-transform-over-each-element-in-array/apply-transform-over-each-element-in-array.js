/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const transformedArr = [];
    arr.forEach((x, index) => {
        transformedArr[index] = fn(x, index);
    });

    return transformedArr;
};