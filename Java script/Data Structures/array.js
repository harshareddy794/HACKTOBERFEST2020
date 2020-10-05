const names =['max','Manu','Julie','Max'];
console.log(names[1]);
console.log(names.length);

// printing all values of array
for(const el of names){
    console.log(el);
}

// push value in array
names.push('Julie');
console.log(names.length);

const julieIndex = names.findIndex(el => el === 'Julie');
names.splice(2,1);
console.log(names)
