function toCamelCase(str){
    let text = "";
    if(str)
      {
        for(var i = 0;i<str.length;i++)
    {
      if(str[i] === '-' || str[i] === '_')
        {
          i++;
          text += str[i].charAt(0).toUpperCase();
        }
      else{
        text += str[i];
      }
    }
      }
    else{
      return text;
    }
    return text;
  }

//   best practise

  function toCamelCase(str){
    return str.replace(/[-_](.)/g, (_, c) => c.toUpperCase());
  }