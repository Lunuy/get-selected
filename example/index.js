
const { getSelected, getSelectedSync } = require("../lib/");

setInterval(() => {
    console.log(getSelectedSync());
}, 500);