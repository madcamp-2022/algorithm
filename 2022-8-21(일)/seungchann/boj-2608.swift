/**
boj-2608.swift
https://www.acmicpc.net/problem/2608
*/

import Foundation

func convertIntToRoman(n num: inout Int) -> String {
    let intDict: [Int : String] = [
        1000:"M", 
        900:"CM", 500:"D", 400:"CD", 100:"C",
        90:"XC", 50:"L", 40:"XL", 10:"X", 
        9: "IX", 5:"V", 4:"IV", 1:"I"
    ]
    var ret: String = ""
    var digit: Float = Float(String(num).count - 1)

    while digit >= 0 {
        var firstDigit = Int(num / Int(pow(10.0, digit)))
        let zeros = Int(pow(10.0, digit))

        if digit < 3 {
            if firstDigit == 9 {
                ret += intDict[firstDigit * zeros]!
                firstDigit -= 9
            } else if firstDigit >= 5 {
                ret += intDict[5 * zeros]!
                firstDigit -= 5
            } else if firstDigit == 4 {
                ret += intDict[4 * zeros]!
                firstDigit -= 4
            }
        }
        
        for _ in stride(from: 0, to: firstDigit, by: 1) { ret += intDict[zeros]! }
        num %= zeros
        digit -= 1
    }

    return ret
}

func convertRomanToInt(r roman: [String]) -> Int {
    let romanDict: [String : Int] = [
        "M":1000, 
        "CM":900, "D":500, "CD":400, "C":100,
        "XC":90, "L":50, "XL":40, "X":10, 
        "IX":9, "V":5, "IV":4, "I":1
        ]
    var ret: Int = 0
    
    var temp = ""
    for (idx, ch) in roman.enumerated() {
        temp += ch
        if idx != roman.count-1 {
            if romanDict[ch]! < romanDict[roman[idx+1]]! { continue }
            else {
                ret += romanDict[temp]!
                temp = ""
            }
        } else {
            ret += romanDict[temp]!
        }
    }
    return ret
}

func solve(_ fir: [String], _ sec: [String]) {
    let firstInt: Int = convertRomanToInt(r: fir)
    let secondInt: Int = convertRomanToInt(r: sec)
    var totalInt: Int = firstInt + secondInt
    print(totalInt)
    
    let totalRoman: String = convertIntToRoman(n: &totalInt)    
    print(totalRoman)
}

func main() {
    let first = readLine()!.map{ String($0) }
    let second = readLine()!.map{ String($0) }
    solve(first, second)
}

main()