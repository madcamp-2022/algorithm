var fs = require('fs');

const solve = (data) => {
    if(data[0] === ':'){
        data = data.substring(1,data.length);
    }
    if(data[data.length-1] === ':'){
        data = data.substring(0,data.length-1);
    }
    const splited = data.split(':');
    return splited.map((split) => {
        return split.length === 0 ? new Array(8 - splited.length + 1).fill('0000').join(':') 
        : split.padStart(4, '0')
    }).join(':');
}
 
function main(){
    const ipv6 = fs.readFileSync('dev/stdin').toString().trim();
    console.log(solve(ipv6));
}

main();