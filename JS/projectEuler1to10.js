//problem 1;
let prob1Counter = 0;
for (let i = 1; i < 1000; i++) {
    if (i % 3 === 0 || i % 5 === 0) prob1Counter += i;
}

document.writeln(prob1Counter);

//even fibonacci number
let a = 1, b = 1, c = 1;
let sum = 0;
for (let i = 1; i < 30; i++) {
    a = b;
    b = a + c;
    c = a;
    if (a % 2 == 0) sum += a;

}
document.writeln(sum);

//largest prime factor
//600851475143

// list out all prime factors in array. 
// pick one that is largest and prime

// const myArr = [];
// for (let i = 600851475143 / 2; i > 5; i--) {
//     if (i % 2 === 0 || i % 3 === 0) continue;
//     myArr.push(i);
// }

//sum square difference

//(2n+1)(n+1)n/6-n(n+1)/2
function pass(number) {
    for (let i = 2; i <= 20; i += 2) {
        if (number % i !== 0) return false
    }
    return true;
}
let found = false;
let prob5count = 20;
while (true) {
    prob5count++;
    if (pass(prob5count)) break;
}

document.writeln(prob5count);


//problem 4
//largest palindrome product
let c = 999;
let d = 999;
let n = false;
while (c > 100 && n === false) {
    while (d > 100) {
        d--;
        if ('' + d * c === ('' + d * c).split("").reverse().join("")) n = true;
    }
    c--;
}

//problem 7

function prime(number) {
    for (let i = Math.floor(Math.sqrt(number)); i > 1; i--) {
        if (number % 2 === 0 && number !== 2 || number % 3 === 0 && number !== 3 || number % 5 === 0 && number !== 5) return false;
        if (number % i === 0) return false;

    }
    return true;
}
let pr7 = 0;
let cn = 2;
while (pr7 != 10001) {
    if (cn % 2 === 0 && cn !== 2 || cn % 3 === 0 && cn !== 3 || cn % 5 === 0 && cn !== 5) continue;
    if (prime(cn)) {
        pr7++;
    }
    cn++;
}
document.write(cn);

// problem 8

let strNum = `73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725`.split("");
let cntr = 0;
let out = [];
for (let j = 0; j < strNum.length; j++) {
    let product = 1;
    for (let i = 0; i < 13; i++) {
        product *= strNum[j + i];
    }
    out.push(product);
}

document.writeln(Math.max(...out));

//problem 9
// more like a permutation way.
let allComb = [];
for (let i = 1; i < 1000; i++) {
    for (let j = 1; j < 1000; j++) {
        for (let k = 1; k < 1000; k++) {
            allComb.push([i, j, k]);
        }
    }
}
allComb.filter(d => d[0] * d[0] + d[1] * d[1] === d[2] * d[2] && d[0] + d[1] + d[2] === 1000);

document.writeln(allComb);

//problem 10
//prime sums below 2 million.
//sieve of eratosthenes
let mySieve = Array.from(Array(2e6).keys);

for (let i = 2; i < mySieve.length; i++) {
    if (typeof mySieve === "number") {

        for (let j = i * i; j < mySieve.length; j += i) {
            mySieve[j] = false;
        }
    }
}

mySieve.filter(a => a !== false);
document.writeln(mySieve.reduce((result, a) => result + a));









