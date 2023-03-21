#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "GenericPlatform/GenericPlatformMisc.h"

// TODO: This should not need to be here. Just here to make tests build.
#include <algorithm>

namespace util
{
    // A signal object may call multiple slots with the
    // same signature. You can connect functions to the signal
    // which will be called when the Emit() method on the
    // signal object is invoked. Any argument passed to Emit()
    // will be passed to the given functions.

    template <typename... Args> class FSignal
    {
    public:
        FSignal() : Slots{}, OnConnection{} {}
        explicit FSignal(TFunction<void(TFunction<void(Args...)> const&)> Connection)
            : Slots{}, OnConnection{Connection}
        {
        }

        ~FSignal() { Slots.Reset(); }

        /**
         * \brief Connects a TFunction to the signal.
         *
         * \param slot A pointer to a function to be called by Emit.
         */
        void Connect(TFunction<void(Args...)> const& Slot) const
        {
            Slots.Emplace(Slot);
            if (OnConnection) {
                OnConnection(Slot);
            }
        }

        /**
         * \brief Calls all connected functions. Each connected function will be called with the
         * argument given.
         *
         * \param p The argument to be used for the slot functions.
         */
        void Emit(Args... Params) const
        {
            std::for_each(Slots.begin(), Slots.end(), [=](auto const& Slot) { Slot(Params...); });
        }

    private:
        mutable TArray<TFunction<void(Args...)>> Slots{};                      /** The slots - subscribers */
        TFunction<void(TFunction<void(Args...)> const&)> const OnConnection{}; /** send slot on connection */
    };

} // namespace util
