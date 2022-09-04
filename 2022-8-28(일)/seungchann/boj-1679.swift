/**
boj-1679.swift
https://www.acmicpc.net/problem/1679
*/

func solve(_ n: Int, _ nums: [Int], _ k: Int) -> String {
    guard nums.contains(1) else { return "jjaksoon win at 0 "}
    
    var q: [(Int, Int)] = [(0, 0)]
    var visited: [Bool] = Array(repeating: false, count: 1001)

    while q.count != 0 {
        let posCnt = q.removeFirst()
        let pos = posCnt.0, cnt = posCnt.1

        for num in nums {
            if visited[pos+num] || cnt+1 > k { continue }
            visited[pos+num] = true
            q.append((pos+num, cnt+1))
        }
    }

    for (idx, val) in visited.enumerated() {
        if idx == 0 { continue }
        if !val { 
            return (idx % 2 == 0 ? "holsoon" : "jjaksoon") + " win at " + String(idx)
        }
    }
    
    return "-1"
}

func main() {
    let N = Int(readLine()!)!
    let nums = readLine()!.split(separator: " ").map { Int(String($0))!}
    let K = Int(readLine()!)!

    print(solve(N, nums, K))
}

main()