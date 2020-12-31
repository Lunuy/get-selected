
const path = require("path");
const ffi = require("ffi-napi");

if(process.platform !== "win32") {
    throw `get-selected supports only win32, but you are ${process.platform}`;
}

const arch = process.arch;

const lib = ffi.Library(path.resolve(__dirname, `../dll/${arch}`), {
    "getSelected": ["string", []]
});

function getSelected() {
    return new Promise((solve, reject) => {
        lib.getSelected.async((err, result) => {
            if(err)
                reject(err);
            else
                solve(result);
        });
    });
}

function getSelectedSync() {
    return lib.getSelected();
}

module.exports = {
    getSelected,
    getSelectedSync
};