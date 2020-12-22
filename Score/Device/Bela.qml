import QtQuick 2.0
import Ossia 1.0 as Ossia

Ossia.WebSockets
{
    property string host: "ws://192.168.7.2:9090"

    // Called whenever the Websocket server sends us a message
    function onMessage(message) {
      var res = JSON.parse(message);

        return [
            { address:"/Matrix/Delay", value: res["vec 0"] },
            { address:"/Matrix/Correlation", value: res["vec 1"] },

        ];

    }

    function createTree() {
        return [
        {
            name: "Matrix",
            children: [
            {
              name: "Delay",
              type: Ossia.Type.List
            },
            {
              name: "Correlation",
              type: Ossia.Type.List
            }
          ]
        },
        {
        name: "request",
          type: Ossia.Int,

          // For the three following functions,
          // the return value is sent to the WS server:

          // 1. When a message is sent from score
          request: function (value) {
              console.log("request: ", value);
              return JSON.stringify(true)
          }
        }
        ];
    }
}
