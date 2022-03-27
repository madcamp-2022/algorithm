var fs = require('fs');

const get = (n, num) => {
    if(num == 0)return 0;
    if(num == 1 || num == 0){
        return n;
    }
    let ret = 0;
    ret += parseInt(n / num) * num;
    return ret;
} 

fs.readFile('dev/stdin', 'utf8', function(err, data) {
    const n = parseInt(data);
    console.log([...new Array(n + 1).keys()].map((idx) => get(n, idx)).reduce((acc, current) => acc + current, 0));
});