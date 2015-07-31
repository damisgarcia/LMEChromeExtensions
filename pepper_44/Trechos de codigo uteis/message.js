 function logMessage(message) {
    logMessageArray.push(message);
    if (logMessageArray.length > kMaxLogMessageLength)
      logMessageArray.shift();

    //document.getElementById('log').textContent = logMessageArray.join('\n');
    console.log(message);
  }