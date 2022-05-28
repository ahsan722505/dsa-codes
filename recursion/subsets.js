const set=[1,2,3];
let overAllAnswer=[];
const findSubsets=(set,index,eachAnswer)=>{
    if(index >= set.length){
        overAllAnswer.push([...eachAnswer]);
        return;
    }
    findSubsets(set,index+1,[...eachAnswer])
    eachAnswer.push(set[index]);
    findSubsets(set,index+1,[...eachAnswer])
}

findSubsets(set,0,[]);
console.log(overAllAnswer);
