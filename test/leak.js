'use strict';

const addon = require('bindings')('addon.node');
const myObject = new addon.MyObject();
let count = 0;

function open() {
  myObject.open(() => {
    count += 1;
    if (count % 1000000 === 0) {
      console.log(count);
    }
    open();
  });
}

open();

