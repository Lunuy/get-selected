
# get-selected
get selected text
(currently support only windows)

```js
const { getSelected, getSelectedSync } = require("get-selected");

setInterval(() => {
    console.log(getSelectedSync());
}, 500);
```