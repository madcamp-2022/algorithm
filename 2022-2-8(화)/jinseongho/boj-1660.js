var fs = require('fs');

const getNaturalSum = (n) => ((n) * (n + 1)) / 2;
const arr = [];
const dp = new Array(300001).fill(987654321);

fs.readFile('dev/stdin', 'utf8', function(err, data) {
    let store = 0;
    let idx = 0;
    let n = parseInt(data);
    while( store + getNaturalSum(idx) <= n){
        store += getNaturalSum(idx);
        arr.push(store);
        idx++;
    }
    dp[0] = 0;
    for(let i = 0; i <= n; i++){
        for(let j = 0; j < arr.length; j++){
            const before = i - arr[j];
            if(before < 0)break;
            dp[i] = Math.min(dp[i], dp[before] + 1);
        }
    }
    console.log(dp[n]);
});