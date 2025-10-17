//--------filter for each
// const name=["tarik","pratik","osumane","sachin"];

// const value=name.forEach((item) => {//item is parameter which takes value of each element of array
//     console.log(item);
// })
// console.log(value);//undefined because forEach does not return anything

// const a=[1,2,3,4,5,6,7,8,9]

 //console.log(a.filter( (num) =>num>4 ))
// const data=a.filter(  (num1)=>{
//     return num1>4;
// })
// console.log(data);
//if we give scope{} then we have to return something or else not
// const b=[];
// a.forEach( (num) => {
//     if(num>4){
//         b.push(num)
//     }
// })
// console.log(b);

// const books=[
//     {title:"book1",price:300, genre:"history"},
//     {title:"book2",price:200, genre:"fiction"},
//     {title:"book3",price:400, genre:"science"},
//     {title:"book4",price:150, genre:"fiction"},
//     {title:"book5",price:500, genre:"history"},
// ]

// // const mybook=books.filter((bk)  => bk.genre ==="fiction")
// // const pubook=books.filter((bk) => {return bk.price>=200  })
// // console.log(mybook);
// // console.log(pubook);
// const mybook=books.filter((bk)  => { return bk.genre ==="fiction"&& bk.price>=200})
// console.log(mybook);

///---------maps
// const myno=[1,2,3,4,5,6,7,8,9]
// // console.log(myno.map((num) => num+10))
// let a=myno.map((num) => num+10)//map 
// console.log(a);

// const no = myno
//         .map((b) => b*10 )
//         .map((b) => b+1)//2 map in single line
//         .filter((b) => b<50);//and a filter (filter true and false)
// console.log(no);
//----reduce method-------------------------
// const arr=[1,2,3,4,5,6]
// // let a=0

// const ttl= arr.reduce( (acc, cur) =>acc +cur,0 )
// console.log(ttl);


// // const ttl = arr.reduce(function(accumalator, reduce){
// //     console.log(`acc:${accumalator} and reduce:${reduce}`);
// //     return accumalator + reduce},0)
// //     console.log(ttl);
// const shop=[
//     {
//         itemname:"cpp",
//         price:2000
//     },
//     {
//         itemname:"java",
//         price:4000
//     },
//     {
//         itemname:"dsa",
//         price:3000
//     },

// ]
// const price=shop.reduce( ( acc,t1) =>(acc +t1.price),0 )
// console.log(price);

let arr=[1,2,3,4]  

arr.forEach( function (a){// for each
    console.log(a*2);
})
arr.forEach((a) => console.log(a*3))//arrow function