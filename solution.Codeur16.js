const readline = require('readline').createInterface(process.stdin, process.stdout);

function min_index(start, end, list) {
    var minI = start
    for (var i = start + 1; i < end; i++) {
        if (list[i] < list[minI]) {
            minI = i
        }
        return minI
    }
}

function reverse(list, a, b) {
    var temp
    while (a < b) {
        temp = list[a]
        list[a] = list[b]
        list[b] = temp
        a += 1
        b -= 1
    }
    return list
}

function reversemax(tab = [], val) {
    var i = val;
    return tab.forEach((el, is) => (el < tab[i] && is >= val ? i = is : true)) || i;
}
const reverseSort = (tab = []) => {
    var cost = 0,
        max, length = tab.length;
    for (let i = 0; i < length - 1; i++) {
        max = reversemax(tab, i);
        tab = reverse(tab, i, max);
        cost += max - i + 1;
    }
    return cost;
};


function reverseort(listes = []) {
    var taille = listes.length
    var cost = 0
    for (var j = 0; j < taille - 1; j++) {
        var minI = min_index(j, taille, listes)
        listes = reverse(listes, j, minI)
        cost += minI - j + 1
    }
    return cost;
}
var max = 0;
var line = 0;


readline.on('close', () => process.exit(0));
readline.on('line', (data) => {
    line++;
    if (!max) max = parseInt(data);
    else {
        if (line % 2) {
            data = data.split(' ')
            var liste = data.map(i => parseInt(i));
            console.log(`Case #${ ( line - 1 ) / 2  }: ${ reverseSort( liste ) }`)
            line - 1 === max * 2 ? readline.close() : {};
        }
    }
});