// // Writing to the console (visible in browser developer tools)
// // console.log("Hello, World!");   ecma and mozilla for reference 
//  console.log("pratik");

// // Writing to an HTML element
// const accID=12364
// let accname="pratik"
// var acccity="pune"
// let accmail;//its good pratice to use let cos var has an issue
// // of block scope and functional scope
// console.table([accID,accname,acccity,accmail])

// let isLoginedin=true //boolean
// //data types
// // num=>2 to the power 52 
// // string =>""
// // Boolean=>true/false
// // symbol=>unique
// // undefined=>not defined
// console.log(typeof null) //object


//------------------data type conversionV6------------------
// let a="11abc";
// console.log(typeof a)
// let value=Number(a)
// console.log(typeof value)
// console.log(value)

//let a= 1;
// let a="osumane";
// let b=Boolean(a);
// console.log(b);

// let n=22;
// let s=String(n)
// console.log(typeof s)
// console.log(s)
//------------------operationsV7--------------------------

// console.log(3+2) //5
// let str1="hello"
// let str2=" world"
// let str3=str1+str2
// console.log(str3) //helloworld
// console.log("1"+2+2);   //122
// console.log(1+2+"2");   //32
// console.log(1+"2"+3); //123
// console.log(+true);//1
// console.log(+"" );//0
//------------------comparion of dataypesV8----------------------
// console.log("2">1) //true
// console.log("02">1) //true
// console.log(null>=0) //true
// console.group(null>0) //false
// console.log("2"===2); //false  
// const a=Symbol('hey')
// const b=Symbol('hey')
// console.log(a===b) //false
//------------------datatypeV9----------------------
// const hero =["dembele", "neymar", "mbappe"];//array
// let obj={name:"pratik",age:"22",city:"pune"}//object
//  const myFucntion=function(){//fucntion
//     console.log("hello")
//  }
//  console.log (typeof hero)//object
//------------------stach and heap memoru in js V10----------------------
//  let myname="pratik" //stack
//  let urname=myname //stack
//  urname="js editor" //stack
//  console.log(myname);
//  console.log(urname);
//  let details={email :"abc.mail", password:"12345"} //heap(object)
//  let details2=details;
//  details2.email="pratikhairwar843@GMAIL.COM"
//  console.log(details.email);
//  console.log(details2.email);
//----------------------strings---------------
// let s1="yo";
// console.log(s1);

// let s2="this is multi line string"
// console.log(s2.length);

// let s3 =s1+s2;//concatenation
// console.log(s3);

// let s5=s2.substring(0, 5);
// console.log(s5);

// console.log(s2.indexOf("multi"));//to search

// console.log(s2.replace(/is/g,"was"));//replace
// console.log(s2.charAt(5));

// let s1="hey"
// let s2=new String("hey")//run time

// console.log(s1==s2);//true
// console.log(s1===s2);//false
// console.log(s1.localeCompare(s2));//0(true)1(false)

// const str =new String("hello world");//passing js string as object
// console.log(str); 

// let str2="hello, java, script"

// console.log(str2.replace("java","js"));

// let a=["apple","banana","grapes"];

// // a.push("mango")//add at last
// // a.unshift("kiwi")//add at first
// // console.log(a);
// // a.pop("")//remove at last
// // console.log(a);
// // console.log(a);
// // The pop() method removes an element from the last index of the array.
// // The shift() method removes the element from the first index of the array.
// // The splice() method removes or replaces the element from the array
// // console.log(a.length);//length

// //  a.forEach(function myfunc(x){

// //     console.log(x);
// // })
// let b=[1,2,3,4,5];

// console.log(b.concat(a));//merge 2 arrays(concat of 2 array)

// console.log(a.toString());//array to string
// console.log(typeof a);
// console.log(typeof b);
// console.log(b.join("|"));   //array to string with separator
// let details ={"name":"pratik","age":"22","city":"pune"}//array of object
// console.log(delete details.city);
// console.log(details);

let a=[11,22,33,44,55];
let b=[1,2,3,4,5];
let c=[21,22,23,24,25];
console.log(a.concat(b,c));
console.log(a.reverse());
console.log(c);





