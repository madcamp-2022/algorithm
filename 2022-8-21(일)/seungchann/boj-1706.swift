import Foundation

func addWord(w: inout [String], t: inout String) {
    if t.count >= 2 {
        w.append(t)
    }
    t = ""
}

func checkWord(x: Int, y: Int, words: inout [String], puzzle: [[String]]) {
    for cy in stride(from: 0, to: y, by: 1) {
        var temp = ""
        for cx in stride(from: 0, to: x, by: 1) {
            if (puzzle[cy][cx] == "#") {
                addWord(w: &words, t: &temp)
            } else {
                temp += puzzle[cy][cx]
            }
        }
        addWord(w: &words, t: &temp)
    }

    for cx in stride(from: 0, to: x, by: 1) {
        var temp = ""
        for cy in stride(from: 0, to: y, by: 1) {
            if (puzzle[cy][cx] == "#") {
                addWord(w: &words, t: &temp)
            } else {
                temp += puzzle[cy][cx]
            }
        }
        addWord(w: &words, t: &temp)
    }
}

func solve(r: Int, c: Int, puzzle: [[String]]) {
    var words: [String] = []
    checkWord(x: c, y: r, words: &words, puzzle: puzzle)
    words.sort()
    print(words[0])
}

func main() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let r = input[0], c = input[1]
    var arr: [[String]] = []

    for _ in stride(from: 0, to: r, by: 1) {
        arr.append(readLine()!.map { String($0) })
    }
    
    solve(r: r, c: c, puzzle: arr)
}

main()