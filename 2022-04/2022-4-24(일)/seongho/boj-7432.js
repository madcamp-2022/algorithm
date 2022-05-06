var fs = require('fs');

/**
 * @param {string[][]} _files
 */
const groupByFirstIndex = (_files) => {
    const group = _files.reduce((prev, _file) => {
        const [first, ...rest] = _file;
        
        if(prev[first] == undefined){
            prev[first] = [];
        }

        if(rest.length !== 0){
            prev[first].push(rest);
        }

        return prev;
    }, {})

    for([key, value] of Object.entries(group)){
        if(value.length !== 0){
            group[key] = groupByFirstIndex(value);
        }
    }

    return Object.keys(group).sort().map((key) => [key, ...group[key]]);
}

/**
 *   
 */
const createBlank = (count) => {
    let blank = "";
    for(let i = 0; i < count; i++){
        blank += " ";
    }
    return blank
}

/**
 * @param {any[]} _files 
 * @param {number} depth
 */
const print = (groupedFiles = [], depth = 0) => {
    for(group of groupedFiles){
        const [key, ...rest] = group;
        const blank = createBlank(depth);
        console.log(`${blank}${key}`);
        if(Array.isArray(rest) && rest.length > 0) {
            print(rest, depth + 1);
        }
    }
}

/**
 * 
 * @param {number} length 
 * @param {string[]} files
 */
const solve = (_files) => {
    const files = _files.map((file) => file.split('\\'));
    const grouped = groupByFirstIndex(files);
    print(grouped);
}
 
function main(){
    const data = fs.readFileSync('dev/stdin').toString().trim().split('\n');
    const [length, ...file] = data;
    solve(file);
}

main();
