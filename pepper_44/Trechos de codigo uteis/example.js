// This function is called by common.js when a message is received from the
// NaCl module.
function handleMessage(message) {
  // In the example, we simply log the data that's received in the message.
  var logEl = document.getElementById('log');
  logEl.textContent += message.data;
}

// From example.js, Step 3:
function moduleDidLoad() {
  // After the NaCl module has loaded, common.naclModule is a reference to the
  // NaCl module's <embed> element.
  //
  // postMessage sends a message to it.
  common.naclModule.postMessage('hello');
}

// In the index.html we have set up the appropriate divs:
<body {attrs}>
  <!-- ... -->
  <div id="listener"></div>
  <div id="log"></div>
</body>
